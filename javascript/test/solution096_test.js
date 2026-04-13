var assert = require('assert');
var solution096 = require('../src/euler/solution096');

describe('Solution096', function() {
  describe('answer', function() {
    it('will answer problem 096', function() {
      assert.equal(solution096.answer(), 24702);
    });
  });
});