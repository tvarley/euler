var assert = require('assert');
var solution092 = require('../src/euler/solution092');

describe('Solution092', function() {
  describe('answer', function() {
    it('will answer problem 092', function() {
      assert.equal(solution092.answer(), 8581146);
    });
  });
});