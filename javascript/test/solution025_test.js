var assert = require('assert');
var solution025 = require('../src/euler/solution025');

describe('Solution025', function() {
  describe('answer', function() {
    it('will answer problem 025', function() {
      assert.equal(solution025.answer(), 4782);
    });
  });
});