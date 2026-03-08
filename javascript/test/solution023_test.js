var assert = require('assert');
var solution023 = require('../src/euler/solution023');

describe('Solution023', function() {
  describe('answer', function() {
    it('will answer problem 023', function() {
      assert.equal(solution023.answer(), 4179871);
    });
  });
});